SELECT person.name
FROM person
WHERE
    gender = 'female'
    AND age > 25
ORDER BY person.name;