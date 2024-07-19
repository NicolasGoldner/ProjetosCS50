SELECT DISTINCT name
FROM (movies as m INNER JOIN stars ON m.id = movie_id)
INNER JOIN people as p ON p.id = person_id
WHERE m.year = 2004
ORDER BY p.birth;
