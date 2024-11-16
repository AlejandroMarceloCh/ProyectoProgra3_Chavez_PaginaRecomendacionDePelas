// src/api/movies.js
import axios from 'axios';

const API_BASE_URL = 'http://localhost:5050';

// Buscar películas por query
export const searchMovies = async (query) => {
    try {
        const response = await axios.post(`${API_BASE_URL}/search`, { query });
        return response.data;
    } catch (error) {
        console.error("Error al buscar películas:", error);
        throw error;
    }
};

// Obtener recomendaciones
export const getRecommendations = async () => {
    try {
        const response = await axios.get(`${API_BASE_URL}/recommendations`);
        return response.data;
    } catch (error) {
        console.error("Error al obtener recomendaciones:", error);
        throw error;
    }
};

// Marcar película como "me gusta"
export const likeMovie = async (movieId) => {
    try {
        await axios.post(`${API_BASE_URL}/like`, { movieId });
    } catch (error) {
        console.error("Error al marcar película como 'Me gusta':", error);
        throw error;
    }
};

// Agregar película a "ver más tarde"
export const watchLaterMovie = async (movieId) => {
    try {
        await axios.post(`${API_BASE_URL}/watchlater`, { movieId });
    } catch (error) {
        console.error("Error al agregar película a 'Ver más tarde':", error);
        throw error;
    }
};

// Obtener lista de películas para "ver más tarde"
export const getWatchLater = async () => {
    try {
        const response = await axios.get(`${API_BASE_URL}/watchlater`);
        return response.data;
    } catch (error) {
        console.error("Error al obtener lista de 'Ver más tarde':", error);
        throw error;
    }
};
