FROM debian:buster

COPY . /commonMs

RUN apt-get update && apt-get install -y bash cmake g++

ENV CC=/usr/bin/gcc
ENV CXX=/usr/bin/g++

EXPOSE 8888

CMD ["/bin/bash"]

