WITH missing_dates AS (
        SELECT
            gd.generated_date
        FROM
            v_generated_dates gd
        WHERE NOT EXISTS (
                SELECT 1
                FROM
                    person_visits pv
                WHERE
                    gd.generated_date = pv.visit_date
            )
    )
SELECT
    generated_date AS missing_date
FROM missing_dates
ORDER BY 1;