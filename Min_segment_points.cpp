#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

typedef std::pair <int, int> Segment;

std::set <int> get_covering_set(std::vector <Segment> segments) {
  std::set <int> result;
  int point = segments[0].second;
  // fix this function
  for (std::size_t i = 0; i < segments.size(); i++) {
    if (point < segments[i].first) {
      point = segments[i].second;
    }
    result.insert(point);
  }

  return result;
}

bool Right_segments(const Segment& a, const Segment& b) {
  return a.second < b.second;
}

int main(void) {
  int segments_count;
  std::cin >> segments_count;
  std::vector <Segment> segments(segments_count);
  for (int i = 0; i < segments_count; i++) {
    std::cin >> segments[i].first >> segments[i].second;
  }
  std::sort(segments.begin(), segments.end(), Right_segments);
  std::set <int> points = get_covering_set(segments);
  std::cout << points.size() << std::endl;
  for (auto it = points.begin(); it != points.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}