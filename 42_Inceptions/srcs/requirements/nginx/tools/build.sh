#!/bin/bash

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=BE/ST=Antwerp/L=Antwerp/O=19/OU=19Antwerp/CN=${DOMAIN}" -keyout ${CERTS_}/nginx-selfsigned.key -out ${CERTS_}/nginx-selfsigned.crt

echo "
server {
    listen 443 ssl;
    server_name localhost ${DOMAIN} www.${DOMAIN};

    ssl_certificate ${CERTS_}/nginx-selfsigned.crt;
    ssl_certificate_key ${CERTS_}/nginx-selfsigned.key;

    ssl_protocols TLSv1.2 TLSv1.3;

    index index.php;
    root /var/www/html;

    location / {
        try_files \$uri \$uri/ =404;
    }

    location ~ \.php$ {
        try_files \$uri =404;
        fastcgi_pass wordpress:9000;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME \$document_root\$fastcgi_script_name;
    }
}
" > /etc/nginx/sites-available/default