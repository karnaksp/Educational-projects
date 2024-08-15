CREATE TABLE IF NOT EXISTS officers (
    id SERIAL PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    RANK VARCHAR(50) NOT NULL,
    CONSTRAINT unique_officer UNIQUE (first_name, last_name, RANK)
);

CREATE TABLE IF NOT EXISTS spaceships (
    id SERIAL PRIMARY KEY,
    alignment VARCHAR(50) NOT NULL,
    name VARCHAR(100) NOT NULL,
    class VARCHAR(50) NOT NULL,
    LENGTH FLOAT NOT NULL,
    crew_size INTEGER NOT NULL,
    armed BOOLEAN NOT NULL,
    hostile BOOLEAN NOT NULL,
    speed FLOAT,
    CONSTRAINT unique_spaceship_name UNIQUE (name)
);

CREATE TABLE IF NOT EXISTS spaceship_officers (
    spaceship_id INTEGER REFERENCES spaceships (id),
    officer_id INTEGER REFERENCES officers (id),
    PRIMARY KEY (spaceship_id, officer_id)
);