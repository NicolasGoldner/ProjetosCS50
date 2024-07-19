SELECT m.title
FROM (movies as m INNER JOIN stars ON m.id = movie_id INNER JOIN people as p ON p.id = person_id)
WHERE p.name LIKE '%Bradley Cooper%' AND m.title IN (SELECT m.title
FROM (movies as m INNER JOIN stars ON m.id = movie_id INNER JOIN people as p ON p.id = person_id)
WHERE p.name LIKE '%Jennifer Lawrence%')
