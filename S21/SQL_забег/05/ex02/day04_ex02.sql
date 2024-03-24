CREATE VIEW
    v_generated_dates AS
SELECT
    generated_date :: DATE AS generated_date
FROM
    GENERATE_SERIES(
        '2022-01-01' :: DATE,
        '2022-01-31' :: DATE,
        '1 day'
    ) AS generated_date
ORDER BY generated_date;

SELECT
    COUNT(*) = 31 AS CHECK,
    MIN(generated_date) AS check1,
    MAX(generated_date) AS check2
FROM v_generated_dates;