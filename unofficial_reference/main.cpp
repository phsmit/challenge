#include "../../point_search.h"
#include <iterator>
#include <vector>
#include <algorithm>

struct SearchContext
{
	SearchContext(const Point* points_begin, const Point* points_end);
	int32_t search(const Rect rect, const int32_t count, Point* out_points);

	std::vector<Point> points;

};

inline bool is_inside(const Rect &rect, const Point &point)
{
	if( rect.lx <= point.x && rect.hx >= point.x &&
		rect.ly <= point.y && rect.hy >= point.y )
		return true;
	return false;
}

SearchContext::SearchContext(const Point* points_begin, const Point* points_end)
	:points(points_begin, points_end)
{
	using namespace std;
	sort( begin(points), end(points), [&](Point a, Point b){return a.rank < b.rank;} );
}

int32_t
SearchContext::search(const Rect rect, const int32_t count, Point* out_points)
{
	using namespace std;
	int32_t result_count = 0;
	for (auto i=begin(points); result_count < count && i != end(points); i = next(i)) {
		if (is_inside(rect, *i)) {
			*out_points = *i;
			result_count++;
			out_points++;
		}
	}
	return result_count;
}

extern "C" __declspec(dllexport)
SearchContext* __stdcall
create(const Point* points_begin, const Point* points_end)
{
	return new SearchContext(points_begin, points_end);
}

extern "C" __declspec(dllexport)
int32_t __stdcall
search(SearchContext* sc, const Rect rect, const int32_t count, Point* out_points)
{
	return sc->search(rect, count, out_points);
}

extern "C" __declspec(dllexport)
SearchContext* __stdcall
destroy(SearchContext* sc)
{
	delete sc;
	return nullptr;
}