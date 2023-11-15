#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int
solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int const t = bandage[0];
    int const healPerSec = bandage[1];
    int const additionalHeal = bandage[2];

    int const maxHealth = health;

    int streak = 0;

    for (int currentTime = 0, index = 0; index < attacks.size();
         ++currentTime) {
        vector<int> const& attack = attacks[index];
        if (currentTime == attack[0]) {
            streak = 0;
            health -= attack[1];
            if (health <= 0) {
                break;
            }
            ++index;
        } else {
            ++streak;
            int const heal = healPerSec + (streak == t ? additionalHeal : 0);
            streak %= t;
            health = min((health + heal), maxHealth);
        }
    }

    return health > 0 ? health : -1;
}
