-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports
WHERE year = 2020 AND month = 7 AND day = 28 AND street = “Chamberlin Street”
-------------------------------------------------------
SELECT * FROM interviews
WHERE transcript LIKE “%courthouse%”
AND year = 2020 AND month = 7 AND day = 28
----------------------------------------------------------
SELECT * FROM courthouse_security_logs
WHERE year = 2020 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25
--------------------------------------------------------
SELECT * FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28
AND atm_location = “Fifer Street”
AND transaction_type = “withdraw”
------------------------------------------------------------------------
SELECT * FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28
AND duration < 60
----------------------------------------------------
SELECT * FROM flights
WHERE year = 2020 AND month = 7 AND day = 29
ORDER BY hour, minute ASC LIMIT 1
---------------------------------------------------
SELECT name FROM people
WHERE people.license_plate IN (
    SELECT license_plate FROM courthouse_security_logs
    WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25)
AND people.id IN (
    SELECT person_id FROM bank_accounts
    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
    WHERE atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28
    AND transaction_type = “withdraw”
    AND atm_transactions.atm_location = “Fifer Street”)

AND people.phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2020 AND month = 7 AND day = 28
    AND duration < 60)

AND people.passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id IN (
        SELECT id FROM flights WHERE year = 2020 AND month = 7 AND day = 29
        ORDER BY hour, minute ASC LIMIT 1))
-------------------------------------------------------------------------------------------
SELECT city FROM airports
WHERE id = 4

SELECT name FROM people
WHERE phone_number IN (
    SELECT receiver FROM phone_calls
    WHERE year = 2020 AND month = 7 AND day = 28
    AND caller = (
        SELECT phone_number FROM people WHERE name = “Ernest”)
    AND duration < 60)
