#include <stdio.h>
#include <stdlib.h>

// Define a structure for a 2D point
struct Point {
    int x, y;
};

// A global variable 'p0' to store the point with the lowest y-coordinate.
// This will be the pivot point for the angular sort.
struct Point p0;

// Utility function to swap two Point structs
void swap(struct Point *p1, struct Point *p2) {
    struct Point temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Calculates the squared distance between two points.
// Squaring avoids floating-point numbers and is sufficient for comparisons.
int distSq(struct Point p1, struct Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

// Finds the orientation of the ordered triplet (p, q, r).
// Returns:
// 0 --> p, q, and r are collinear
// 1 --> Clockwise
// 2 --> Counter-clockwise
int orient(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // 1 for Clockwise, 2 for Counter-clockwise
}

// Comparison function for qsort().
// It sorts points based on their polar angle with respect to the pivot 'p0'.
int compare(const void *vp1, const void *vp2) {
    struct Point *p1 = (struct Point *)vp1;
    struct Point *p2 = (struct Point *)vp2;

    // Find the orientation
    int o = orient(p0, *p1, *p2);

    if (o == 0) {
        // If points are collinear, put the closer point first
        // so the farthest point is kept.
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
    }

    // If counter-clockwise (2), p1 comes before p2.
    return (o == 2) ? -1 : 1;
}

// Main function to find and print the convex hull
int main() {
    int n;
    scanf("%d", &n);

    struct Point pts[n];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &pts[i].x, &pts[i].y);
    }

    // 1. Find the bottom-most point.
    // If there's a tie, use the left-most point among them.
    int ymin = pts[0].y;
    int min = 0;
    for (int i = 1; i < n; i++) {
        if ((pts[i].y < ymin) || (pts[i].y == ymin && pts[i].x < pts[min].x)) {
            ymin = pts[i].y;
            min = i;
        }
    }

    // 2. Swap the found minimum point with the first point
    swap(&pts[0], &pts[min]);

    // Set the global pivot 'p0' to this first point
    p0 = pts[0];

    // 3. Sort the remaining (n-1) points based on polar angle
    //    around p0.
    qsort(&pts[1], n - 1, sizeof(struct Point), compare);

    // 4. Remove collinear points (keeping only the farthest one)
    //    This creates a modified array 'pts' of size 'm'.
    int m = 1; // 'm' will be the size of the modified array
    for (int i = 1; i < n; i++) {
        // Skip points if they are collinear with the next point
        while (i < n - 1 && orient(p0, pts[i], pts[i + 1]) == 0) {
            i++;
        }
        pts[m++] = pts[i];
    }

    // A convex hull is not possible with fewer than 3 unique points
    if (m < 3) {
        printf("Convex hull not possible\n");
        return 0;
    }

    // 5. Create the stack for the Graham Scan
    struct Point stack[n]; // Stack can have at most 'n' points
    int top = 0;

    stack[0] = pts[0];
    stack[1] = pts[1];
    stack[2] = pts[2];
    top = 2;

    // 6. Process the remaining 'm-3' points
    for (int i = 3; i < m; i++) {
        // Keep removing the top of the stack while the new point 'pts[i]'
        // makes a non-left (clockwise or collinear) turn with the top two
        // stack items. We want only left turns (counter-clockwise).
        while (top >= 1 && orient(stack[top - 1], stack[top], pts[i]) != 2) {
            top--; // Pop from stack
        }

        // Push the new point 'pts[i]' onto the stack
        stack[++top] = pts[i];
    }

    // 7. Print the points in the convex hull
    printf("Points in Convex Hull:\n");
    for (int i = 0; i <= top; i++) {
        printf("(%d,%d)\n", stack[i].x, stack[i].y);
    }

    return 0;
}