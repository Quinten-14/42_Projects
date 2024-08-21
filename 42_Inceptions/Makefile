all:
	@echo "Usage: make [up | build | rebuild | stop | down | logs | status | clean | fclean | re]"
	@echo "up:		Launch the services"
	@echo "build:		Build the services"
	@echo "rebuild:	Rebuild the services"
	@echo "stop:		Stop the services"
	@echo "down:		Stop and remove the services"
	@echo "logs:		Show the logs of the services"
	@echo "status:		Show the status of the services"
	@echo "clean:		Remove the services"
	@echo "fclean:		Remove the services and the data"
	@echo "re:		Rebuild and launch the services"

up:
	@mkdir -p /home/qraymaek/data
	@mkdir -p /home/qraymaek/data/wordpress
	@mkdir -p /home/qraymaek/data/mariadb
	@docker -compose -f srcs/docker-compose.yml up -d

build:
	@docker-compose -f srcs/docker-compose.yml build

rebuild:
	@docker-compose -f srcs/docker-compose.yml up --build --no-cache

stop:
	@docker-compose -f srcs/docker-compose.yml stop

down:
	@docker-compose -f srcs/docker-compose.yml down

logs:
	@docker-compose -f srcs/docker-compose.yml logs

status:
	@docker-compose -f srcs/docker-compose.yml ps

clean:
	@docker-compose -f srcs/docker-compose.yml down --rmi all --volumes

fclean:	clean
	rm -rf /home/qraymaek/data

re:	clean rebuild up

.PHONY: all up build rebuild stop down logs status clean fclean re