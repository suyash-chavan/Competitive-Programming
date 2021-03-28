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

// Total Disjoint Components

vector < vector < long long > > graph(MAXN);
unordered_map < long long, long long > visited;

void dfs(long long node, vector < long long > & component) {
    if (visited[node])
        return;

    component.push_back(node);

    visited[node]++;

    for (long long child: graph[node])
        dfs(child, component);
}

vector < vector < long long > > ConnectedComponents(long long n) {
    vector < vector < long long > > components;

    for (long long node = 1; node <= n; node++) {
        if (visited[node])
            continue;

        vector < long long > component;
        dfs(node, component);

        if (component.size())
            components.push_back(component);
    }

    return components;
}
