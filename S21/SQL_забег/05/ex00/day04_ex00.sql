-- Active: 1704644311037@@127.0.0.1@5432@pizza
-- females
CREATE VIEW v_persons_female AS
SELECT
    id,
    NAME,
    age,
    gender,
    address
FROM person
WHERE gender = 'female';

-- males
CREATE VIEW v_persons_male AS
SELECT
    id,
    NAME,
    age,
    gender,
    address
FROM person
WHERE gender = 'male';