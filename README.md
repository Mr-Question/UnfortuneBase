# UnfortuneBase
Header-only library providing common data structures, such as Point, Node, Circle, HalfEdge, Mesh
as well as auxiliary tools to work with 2D point sets and meshes built upon them.

Generally intended to become a lightweight base for prototypes of triangulation algorithms.

The following functionality is provided:
* reading point sets from .xy files of "x y" line format;
* generation of regular point sets for debug needs;
* writing point sets and meshes to .obj files;
* computing bounding box of the given point sets;
* scaling point sets by given factor;
* iterating through triangles and links of meshes represented by half-edge data structure;
* adding triangles to mesh, performing edge-flip operation.
