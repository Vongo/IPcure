#include <stdio.h>
#include <pcap.h>
#include <limits.h> //included for INT_MAX, should be deleted anytime soon
#include <string.h>

int main(int argc, char *argv[])
{
	//Define the interface to listen
	char *device = argv[10], errbuf[PCAP_ERRBUF_SIZE]; //error string
	printf("//WELCOME TO IPcure //\n\nWhich interface do you want to use ? (ctrl+D for automatic selection)\n");
	scanf("%s", device);
	if (strlen(device)==0){
		device = pcap_lookupdev(errbuf);
	}
	printf("Device: %s\n", device);

	//Open the device for sniffing
	pcap_t *handle;		//Session handle
	bool promisc = 1;	//Set true to enable promiscuous mode 
	int to_ms = 2000;	//Read timeout in milliseconds
	handle = pcap_open_live(device, BUFSIZ, promisc, to_ms, errbuf);
	if (handle == NULL) {
		fprintf(stderr, "Couldn't open device %s: %s\n", device, errbuf);
		return(2);
	}

	//Filter the traffic
	struct bpf_program fp;		/* The compiled filter expression */
	char filter_exp[] = "port 80";	/* The filter expression */
	bpf_u_int32 mask;		/* The netmask of our sniffing device */
	bpf_u_int32 net;		/* The IP of our sniffing device */
	
	if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
		fprintf(stderr, "Can't get netmask for device %s\n", device);
		net = 0;
		mask = 0;
	}
	if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
		fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
		return(2);
	}
	if (pcap_setfilter(handle, &fp) == -1) {
		fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
		return(2);
	}

	//Read the traffic
	struct pcap_pkthdr header;	/* The header that pcap gives us */
	const u_char *packet;	/* The actual packet */
	int i=0;
	while (i<10){
		packet = pcap_next(handle, &header);
		printf("Jacked a packet with length of [%d]\n", header.len);
		i=i+1;
	}

	//Close the session
	pcap_close(handle);
	return(0);

}