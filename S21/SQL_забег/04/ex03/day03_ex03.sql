WITH all_visit_women AS (
        SELECT
            pz.name AS pizzeria_name
        FROM person AS p
            JOIN person_visits AS pv ON p.id = pv.person_id
            JOIN pizzeria AS pz ON pv.pizzeria_id = pz.id
        WHERE
            gender = 'female'
    ),
    all_visit_men AS (
        SELECT
            pz.name AS pizzeria_name
        FROM person AS p
            JOIN person_visits AS pv ON p.id = pv.person_id
            JOIN pizzeria AS pz ON pv.pizzeria_id = pz.id
        WHERE
            gender = 'male'
    ),
    only_woman AS (
        SELECT pizzeria_name
        FROM all_visit_women
        EXCEPT ALL
        SELECT
            all_visit_men.pizzeria_name
        FROM
            all_visit_men
    ),
    only_man AS (
        SELECT pizzeria_name
        FROM all_visit_men
        EXCEPT ALL
        SELECT pizzeria_name
        FROM all_visit_women
    )
SELECT only_man.pizzeria_name
FROM only_man
UNION ALL
SELECT
    only_woman.pizzeria_name
FROM only_woman
ORDER BY 1;