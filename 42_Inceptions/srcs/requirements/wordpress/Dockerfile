FROM debian:buster

ARG DOMAIN
ARG TITLE
ARG DB_NAME
ARG DB_HOST
ARG USER
ARG USER_EMAIL
ARG USER_PASS
ARG ADMIN_USER
ARG ADMIN_PASS
ARG ADMIN_EMAIL

ENV DOMAIN=$DOMAIN
ENV TITLE=$TITLE
ENV DB_NAME=$DB_NAME
ENV DB_HOST=$DB_HOST
ENV USER=$USER
ENV USER_EMAIL=$USER_EMAIL
ENV USER_PASS=$USER_PASS
ENV ADMIN_USER=$ADMIN_USER
ENV ADMIN_PASS=$ADMIN_PASS
ENV ADMIN_EMAIL=$ADMIN_EMAIL

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y php-fpm && apt-get install -y php-mysql && apt-get install -y curl

COPY ./tools/ /

RUN chmod +x /build.sh
RUN chmod +x /start.sh

RUN /build.sh

CMD [ "/start.sh" ]