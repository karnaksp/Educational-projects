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

EXPOSE 8082
ENTRYPOINT ["./wait-for-it.sh", "${POSTGRES_HOST}:${POSTGRES_PORT}", "--", "java", "-jar", "app.jar"]
