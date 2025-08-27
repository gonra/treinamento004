FROM oraclelinux:8
# oracle & dependencies
RUN dnf -y install openssh-server openssh-clients
RUN dnf -y install gcc gcc-c++ make git
RUN dnf -y install which net-tools iputils iproute vi nano gzip zip unzip socat unix2dos
COPY extra/ol8_developer_EPEL.repo /etc/yum.repos.d
RUN dnf repolist
RUN dnf -y install oracle-instantclient-release-el8 
RUN dnf -y install oracle-instantclient19.28-basic
RUN dnf -y install oracle-instantclient19.28-devel
RUN dnf -y install oracle-instantclient19.28-sqlplus
RUN dnf -y install oracle-instantclient19.28-tools

USER root
WORKDIR /usr/src/app && \
	mkdir oracle 
COPY extra/tnsnames.ora /usr/src/app/oracle
EXPOSE 8080 8443 9091 9092 9093 9094 9095
COPY extra/oracle-instantclient19.28-precomp-19.28.0.0.0-1.el8.x86_64.rpm /usr/src/app/
RUN dnf -y install /usr/src/app/oracle-instantclient19.28-precomp-19.28.0.0.0-1.el8.x86_64.rpm
WORKDIR /
RUN mkdir tools && \
	cd tools && \
	mkdir oracle && \
	cd oracle && \
	mkdir 19 && \
	cd 19 && \
	ln -s /usr/lib/oracle/19.28/client64/bin bin && \
	ln -s /usr/include/oracle/19.28/client64/ include && \
	ln -s /usr/lib/oracle/19.28/client64/lib lib && \
	ln -s lib/precomp precomp





