{-# OPTIONS_GHC -Wall -Wextra -Werror #-}

module Strain (keep, discard) where

discard :: (a -> Bool) -> [a] -> [a]
discard p = filter (not . p)

keep :: (a -> Bool) -> [a] -> [a]
keep = filter
