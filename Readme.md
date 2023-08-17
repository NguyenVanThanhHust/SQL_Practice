For MySQL, pull docker image:
```
docker pull container-registry.oracle.com/mysql/community-server:latest
```
build docker container
```
docker run --restart on-failure -d container-registry.oracle.com/mysql/community-server:latest
```