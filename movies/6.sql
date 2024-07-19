SELECT AVG(rating)
FROM ratings
INNER JOIN movies
WHERE id = movie_id
    AND year = 2012;
