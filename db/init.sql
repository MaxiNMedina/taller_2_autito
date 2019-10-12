CREATE DATABASE autito;
use autito;

CREATE TABLE user (
  name VARCHAR(255),
  password VARCHAR(255)
);

INSERT INTO user
  (name, password)
VALUES
  ('maxi', 'maxi123'),
  ('viru', 'viru123');