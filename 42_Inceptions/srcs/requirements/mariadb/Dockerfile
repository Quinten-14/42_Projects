FROM debian:buster

ARG DB_NAME
ARG ROOT_PASS
ARG ADMIN_USER
ARG ADMIN_PASS

ENV DB_NAME=$DB_NAME
ENV ROOT_PASS=$ROOT_PASS
ENV ADMIN_USER=$ADMIN_USER
ENV ADMIN_PASS=$ADMIN_PASS

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y mariadb-server

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/start.sh /start.sh

RUN chmod +x /start.sh

CMD [ "/start.sh" ]