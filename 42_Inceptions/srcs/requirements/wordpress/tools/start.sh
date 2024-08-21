#!/bin/bash

cd /var/www/html

if [ ! -f wp-config.php ]; then
    wp config create --dbname=${DB_NAME} --dbuser=${ADMIN_USER} --dbpass=${ADMIN_PASS} --dbhost=${DB_HOST} --allow-root
fi

wp core install --url="${DOMAIN}" --title="${TITLE}" --admin_user="${ADMIN_USER}" --admin_password="${ADMIN_PASS}" --admin_email="${ADMIN_EMAIL}" --skip-email --allow-root || true

wp user create ${USER} ${USER_EMAIL} --role=author --user_pass=${USER_PASS} --allow-root || true

wp theme install https://downloads.wordpress.org/theme/twentytwenty.1.5.zip --activate --allow-root || true

mkdir -p /run/php

/usr/sbin/php-fpm7.3 -F