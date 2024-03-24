INSERT INTO
    person_visits
SELECT COALESCE(MAX(pv.id), 0) + 1, p.id, pz.id, DATE ('2022-02-24')
FROM
    person_visits AS pv
    CROSS JOIN person AS p
    CROSS JOIN pizzeria AS pz
WHERE
    p.name = 'Denis'
    AND pz.name = 'Dominos'
GROUP BY
    p.id,
    pz.id;

INSERT INTO
    person_visits
SELECT COALESCE(MAX(pv.id), 0) + 1, p.id, pz.id, DATE ('2022-02-24')
FROM
    person_visits AS pv
    CROSS JOIN person AS p
    CROSS JOIN pizzeria AS pz
WHERE
    p.name = 'Irina'
    AND pz.name = 'Dominos'
GROUP BY
    p.id,
    pz.id;

DELETE FROM person_visits
WHERE (
        person_id, pizzeria_id, visit_date
    ) IN (
        SELECT p.id, pz.id, DATE '2022-02-24'
        FROM person p
            JOIN pizzeria pz ON pz.name = 'Dominos'
        WHERE
            p.name IN ('Denis', 'Irina')
    );