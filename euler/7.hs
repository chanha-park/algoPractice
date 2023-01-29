{-# OPTIONS_GHC -Wall -Wextra -Wall #-}

import Data.Map

main :: IO ()
main = print (primes !! 10000)

primes :: [Integer]
primes = sieve [2 ..]
  where
    sieve xs = sieve' xs Data.Map.empty
    sieve' [] _ = []
    sieve' (x : xs) table = case Data.Map.lookup x table of
      Nothing -> x : sieve' xs (Data.Map.insert (x * x) [x] table)
      Just facts -> sieve' xs (Prelude.foldl reinsert (delete x table) facts)
        where
          reinsert table' prime = insertWith (++) (x + prime) [prime] table'
