typedef struct location {
    int data;
    const struct location *adj[2];
} location;

const location B;
const location C;

const location A = {1, {&B, &C}};
const location B = {3, {&A, &C}};
const location C = {8, {&A, 0}};

int main() {
    return A.adj[0]->adj[1]->data;
}

