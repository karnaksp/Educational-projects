WITH all_dates AS (
    SELECT generate_series('2022-01-01', '2022-01-10', '1 day'::interval) AS visit_date
),
person_visits_dates AS (
    SELECT DISTINCT visit_date
    FROM person_visits
    WHERE person_id IN (1, 2)
    AND visit_date BETWEEN '2022-01-01' AND '2022-01-10'
)
SELECT visit_date::DATE
FROM all_dates
WHERE visit_date NOT IN (
    SELECT visit_date
    FROM person_visits_dates
)
ORDER BY visit_date ASC;