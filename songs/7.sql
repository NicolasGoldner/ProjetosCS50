SELECT AVG(songs.energy) as avgEnergy
FROM songs, artists
WHERE songs.artist_id = artists.id
AND artists.name = "Drake";
