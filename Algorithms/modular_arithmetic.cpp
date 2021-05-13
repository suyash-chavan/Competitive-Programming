/*

   _____                       _        _____ _                            
  / ____|                     | |      / ____| |                           
 | (___  _   _ _   _  __ _ ___| |__   | |    | |__   __ ___   ____ _ _ __  
  \___ \| | | | | | |/ _` / __| '_ \  | |    | '_ \ / _` \ \ / / _` | '_ \ 
  ____) | |_| | |_| | (_| \__ \ | | | | |____| | | | (_| |\ V / (_| | | | |
 |_____/ \__,_|\__, |\__,_|___/_| |_|  \_____|_| |_|\__,_| \_/ \__,_|_| |_|
                __/ |                                                      
               |___/                                                       


*/

const long long MOD = 1e9 + 7;

void add(long long &a, long long b)
{
    a = (a + MOD) % MOD;
    b = (b + MOD) % MOD;

    a = (a + b) % MOD;
}

void substract(long long &a, long long b)
{
    a = (a + MOD) % MOD;
    b = (b + MOD) % MOD;

    a = (a - b) % MOD;
    a = (a + MOD) % MOD;
}

void multiply(long long &a, long long b)
{
    a = (a + MOD) % MOD;
    b = (b + MOD) % MOD;

    a = (a * b) % MOD;
}
