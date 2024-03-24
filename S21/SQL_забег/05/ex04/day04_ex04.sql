CREATE VIEW
    v_symmetric_union AS
SELECT person_id
FROM (
        -- (R - S)
        SELECT pv1.person_id
        FROM person_visits pv1
        WHERE
            pv1.visit_date = '2022-01-02'
        EXCEPT
        SELECT pv2.person_id
        FROM person_visits pv2
        WHERE
            pv2.visit_date = '2022-01-06'
        UNION
        -- (S - R)
        SELECT pv2.person_id
        FROM person_visits pv2
        WHERE
            pv2.visit_date = '2022-01-06'
        EXCEPT
        SELECT pv1.person_id
        FROM person_visits pv1
        WHERE
            pv1.visit_date = '2022-01-02'
    ) AS symmetric_union_result
ORDER BY person_id;

SELECT * FROM v_symmetric_union;