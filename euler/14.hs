{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

-- import Data.Map

main :: IO ()
main =
    print
        . last
        . maximum
        . Prelude.map ((<*>) [collatzLen 0, id] . pure)
        $ [1 .. 999999]

collatz :: Int -> Int
collatz n
    | even n = div n 2
    | otherwise = 3 * n + 1

collatzLen :: Int -> Int -> Int
collatzLen acc 1 = 1 + acc
collatzLen acc n = collatzLen (1 + acc) (collatz n)

-- collatzLen :: Int -> Int
-- collatzLen n = collatzLen' n 0 Data.Map.empty

-- collatzLen' :: Int -> Int -> Map Int Int -> Int
-- collatzLen' 1 acc _ = 1 + acc
-- collatzLen' n acc m = case Data.Map.lookup n m of
--     Just val -> val + acc
--     Nothing -> collatzLen' n' (1 + acc) (Data.Map.insert n (collatzLen' n' 0 m) m)
--       where
--         n' = collatz n
