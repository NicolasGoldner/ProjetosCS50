SELECT DISTINCT p.name
FROM (movies as m INNER JOIN stars ON m.id = movie_id INNER JOIN people as p ON p.id = person_id)
WHERE  m.title IN (SELECT m.title
FROM (movies as m INNER JOIN stars ON m.id = movie_id INNER JOIN people as p ON p.id = person_id)
WHERE p.name LIKE '%Kevin Bacon%' AND p.birth = 1958) AND NOT (p.name LIKE '%Kevin Bacon%' AND p.birth = 1958);
