SELECT
    order_date,
    person.name || ' (age:' || age || ')' AS person_information
FROM person_order
    NATURAL JOIN person
ORDER BY
    order_date ASC,
    person_information ASC;