-- Active: 1706346565365@@127.0.0.1@5432@pizza
SELECT person_id, COUNT(*) AS count_of_visits
FROM person_visits
GROUP BY
    person_id
ORDER BY count_of_visits DESC, person_id ASC;