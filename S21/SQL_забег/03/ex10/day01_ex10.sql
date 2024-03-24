SELECT
    person1.name AS person1_name,
    person2.name AS person2_name,
    person1.address AS common_address
FROM person person1
    JOIN person person2 ON person1.address = person2.address AND person1.id > person2.id
ORDER BY
    person1.name,
    person2.name,
    person1.address;