FROM maven:3.8.4-openjdk-17-slim AS build
WORKDIR /app
COPY pom.xml ./
RUN mvn -B dependency:go-offline
COPY src ./src
RUN mvn -B package -DskipTests

FROM openjdk:17-slim
WORKDIR /app
COPY --from=build /app/target/*.jar app.jar
COPY wait-for-it.sh /app/wait-for-it.sh
RUN chmod +x /app/wait-for-it.sh
EXPOSE 8083
ENTRYPOINT ["./wait-for-it.sh", "${POSTGRES_HOST}:${POSTGRES_PORT}", "${RABBIT_MQ_HOST}:${RABBIT_MQ_PORT}", "${HOTEL_SERVICE_HOST}:${HOTEL_SERVICE_PORT}", "${PAYMENT_SERVICE_HOST}:${PAYMENT_SERVICE_PORT}", "${LOYALTY_SERVICE_HOST}:${LOYALTY_SERVICE_PORT}", "--", "java", "-jar", "app.jar"]

