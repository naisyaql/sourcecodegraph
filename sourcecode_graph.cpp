#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Struktur Vertex
struct Vertex {
    std::string nama;
    std::unordered_map<std::string, int> tetangga;
// Tetangga dan waktu tempuh (dalam menit)
    Vertex(const std::string& _nama) : nama(_nama) {}
};

int main() {
    // Membuat vertex-vertex (kota-kota di Provinsi Jawa Timur)
    std::vector<Vertex> vertices;
    vertices.emplace_back("Medan");
    vertices.emplace_back("Binjai");
    vertices.emplace_back("Stabat");
    vertices.emplace_back("Sibolangit");
    vertices.emplace_back("Kabanjahe");
    vertices.emplace_back("Berastagi");
    vertices.emplace_back("Raya");
    vertices.emplace_back("Sidikalang");
    vertices.emplace_back("Siantar");
    vertices.emplace_back("Samosir");

    // Menghubungkan vertex-vertex (mengisi tetangga dan waktu tempuh)
    vertices[0].tetangga = { { "Binjai", 39 }, { "Stabat", 63 }, { "Sibolangit", 87 }, { "Kabanjahe", 158 } };
    vertices[1].tetangga = { { "Medan", 39 }, { "Stabat", 32 }, { "Kabanjahe", 155 } };
    vertices[2].tetangga = { { "Sibolangit", 128 }, { "Raya", 282 }, { "Berastagi", 171 } };
    vertices[3].tetangga = { { "Stabat", 124 }, { "Berastagi", 38 }, { "Samosir", 271 } };
    vertices[4].tetangga = { { "Raya", 120 }, { "Binjai", 154 }, { "Sibolangit", 60 } };
    vertices[5].tetangga = { { "Medan", 137 }, { "Siantar", 190 }, { "Samosir", 246 } };
    vertices[6].tetangga = { { "Medan", 248 }, { "Sidikalang", 156 }, { "Siantar", 60 }, { "Berastagi", 136 } };
    vertices[7].tetangga = { { "Medan", 274 }, { "Samosir", 143 }, { "Stabat", 304 } };
    vertices[8].tetangga = { { "Medan", 155 }, { "Binjai", 170}, { "Raya", 178 } };
    vertices[9].tetangga = { { "Medan", 339 } };

    // Mengakses informasi vertex dan waktu tempuh
    for(const auto& vertex : vertices) {
        std::cout << "Nama Kota: " << vertex.nama << std::endl;
        std::cout << "Kota Tetangga dari " << vertex.nama << " (Waktu Tempuh):" << std::endl;
        for (const auto& tetangga : vertex.tetangga) {
            std::cout << "- " << tetangga.first << " (" << tetangga.second << " menit)" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}