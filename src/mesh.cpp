#include <iostream>
#include <vector>
#include <unordered_map>
#include <glm/glm.hpp>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

#include "mesh.hpp"

Mesh::Mesh(const char* fileName){
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string err;

	if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &err, fileName)) {
		throw std::runtime_error(err);
	}

	std::unordered_map<Vertex, uint32_t> uniqueVertices = {};
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

    for(const auto& shape : shapes){
        for(const auto& index : shape.mesh.indices){
            Vertex vertex;
			vertex.pos = {
				attrib.vertices[3 * index.vertex_index + 0],
				attrib.vertices[3 * index.vertex_index + 1],
				attrib.vertices[3 * index.vertex_index + 2]
			};
			vertex.texCoord = {
				attrib.texcoords[2 * index.texcoord_index + 0],
				attrib.texcoords[2 * index.texcoord_index + 1]
			};
			vertex.normal = {
                attrib.normals[3 * index.normal_index + 0],
                attrib.normals[3 * index.normal_index + 1],
                attrib.normals[3 * index.normal_index + 2]
			};
			if(uniqueVertices.count(vertex) == 0) {
				uniqueVertices[vertex] = static_cast<uint32_t>(vertices.size());
				vertices.push_back(vertex);
			}
			indices.push_back(uniqueVertices[vertex]);
		}
	}

    unsigned int numVertices = vertices.size(), numIndices = indices.size();

	mDrawCount = numIndices;
    glGenVertexArrays(1, &mVertexArrayObject);
    glBindVertexArray(mVertexArrayObject);
    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;
    std::vector<glm::vec3> normals;
    positions.reserve(numVertices);
    texCoords.reserve(numVertices);
    normals.reserve(numVertices);
    for(unsigned int i = 0; i < numVertices; i++){
        positions.push_back(vertices[i].pos);
        texCoords.push_back(vertices[i].texCoord);
        normals.push_back(vertices[i].normal);
    }
    glGenBuffers(NUM_BUFFERS, mVertexArrayBuffers);
    //pos
    glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //texCoord
    glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
    //normals
    glBindBuffer(GL_ARRAY_BUFFER, mVertexArrayBuffers[NORMAL_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(normals[0]), &normals[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
    //indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVertexArrayBuffers[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);
    //bind
    glBindVertexArray(0);
}

Mesh::~Mesh(){
    glDeleteVertexArrays(1, &mVertexArrayObject);
}

void Mesh::draw(){
    glBindVertexArray(mVertexArrayObject);
    glDrawElements(GL_TRIANGLES, mDrawCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
