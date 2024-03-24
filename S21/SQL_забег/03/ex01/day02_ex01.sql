SELECT all_dates::DATE AS visit_date
FROM generate_series('2022-01-01'::date, '2022-01-10'::date, '1 day'::interval) AS all_dates
WHERE all_dates::DATE NOT IN (
    SELECT DISTINCT visit_date
    FROM person_visits
    WHERE person_id IN (1, 2)
    AND visit_date BETWEEN '2022-01-01' AND '2022-01-10'
)
ORDER BY visit_date ASC;