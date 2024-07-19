-- Keep a log of any SQL queries you execute as you solve the mystery.


-- Saber que crime foi reportado nesse dia: FOi antes das 16:36 Menciona a padaria
SELECT *
FROM crime_scene_reports
WHERE year = 2023 AND day = 28 AND month = 7 AND street LIKE '%Humphrey Street%';

-- Mostra o que os entrevistados falaram nesse dia
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning
-- to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
SELECT *
FROM interviews
WHERE year = 2023 AND day = 28 AND month = 7;

-- Mostra oq aconteceu na padaria
SELECT *
FROM bakery_security_logs
WHERE year = 2023 AND day = 28 AND month = 7;

--suspeitos Robin e Bruce
--Ve quem saiu nas cameras entre 8 e 11 horas
SELECT *
FROM bakery_security_logs INNER JOIN people USING(license_plate)
WHERE year = 2023 AND day = 28 AND month = 7 AND hour < 11 AND hour > 8 AND activity LIKE '%exit%'
ORDER BY license_plate;

-- Quem sacou dinheiro cedo
SELECT *
FROM (atm_transactions INNER JOIN bank_accounts USING(account_number)) INNER JOIN people ON person_id = people.id
WHERE year = 2023 AND day = 28 AND month = 7 AND atm_location LIKE '%Leggett Street%' AND transaction_type LIKE '%withdraw%';


-- Achar o VOO mais cedo ID 36
SELECT *
FROM flights
WHERE day = 29
ORDER BY hour, minute;


-- Pessoas que fizeram o voo mais cedo
SELECT *
FROM passengers INNER JOIN people USING(passport_number)
WHERE flight_id = 36;

SELECT *
FROM phone_calls INNER JOIN people ON phone_number = caller
WHERE duration < 60 AND year = 2023 AND day = 28 AND month = 7;

SELECT *
FROM phone_calls INNER JOIN people ON phone_number = receiver
WHERE receiver LIKE '%(375) 555-8161%';


