FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN gcc analyse.c -o program
RUN chmod +x program