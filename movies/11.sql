SELECT title
FROM (movies as m INNER JOIN stars ON m.id = movie_id)
INNER JOIN people as p ON p.id = person_id
INNER JOIN ratings as r USING(movie_id)
WHERE p.name LIKE '%Chadwick Boseman%'
ORDER BY r.rating DESC
LIMIT 5;
