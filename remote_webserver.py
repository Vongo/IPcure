#!/usr/bin/python
# -*- coding: latin-1 -*-
import SimpleHTTPServer # importe un ensemble d'instructions pour servir les requêtes http.
import SocketServer     # importe un ensemble d'instructions pour connecter le programme.
                     # Ces deux ensembles sont disponibles à l'installation de Python
## Python 3 :
# import http.server
# import socketserver
 
# Serveur http de base delivrant le contenu du repertoire courant via le port indique.
PORT = 5432
Handler = SimpleHTTPServer.SimpleHTTPRequestHandler
httpd = SocketServer.TCPServer(("", PORT), Handler)
print "serving at port", PORT
## Python 3 :
# Handler = http.server.SimpleHTTPRequestHandler
# httpd = socketserver.TCPServer(("",PORT), Handler)
# print("à l'écoute sur le port :", PORT)
httpd.serve_forever()