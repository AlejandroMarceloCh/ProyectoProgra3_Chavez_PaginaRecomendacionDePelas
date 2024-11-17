import axios from 'axios';

const API_BASE_URL = 'http://localhost:5050';

// Instancia de Axios para manejar solicitudes con cookies
const apiClient = axios.create({
  baseURL: API_BASE_URL,
  headers: {
    'Content-Type': 'application/json',
  },
  withCredentials: true, // Asegura que las cookies se envíen y gestionen automáticamente
});

// Buscar películas por query
export const searchMovies = async (query) => {
  try {
    const response = await apiClient.post('/search', { query });
    return response.data;
  } catch (error) {
    console.error('Error al buscar películas:', error.response?.data || error.message);
    throw error;
  }
};

// Obtener recomendaciones
export const getRecommendations = async () => {
  try {
    const response = await apiClient.get('/recommendations');
    return response.data;
  } catch (error) {
    console.error('Error al obtener recomendaciones:', error.response?.data || error.message);
    throw error;
  }
};

// Obtener lista de películas para "ver más tarde"
export const getWatchLater = async () => {
  try {
    const response = await apiClient.get('/watchlater');
    return response.data;
  } catch (error) {
    console.error("Error al obtener lista de 'Ver más tarde':", error.response?.data || error.message);
    throw error;
  }
};


export async function likeMovie(movieId) {
    const response = await fetch(`${API_URL}/likeMovie`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ movieId }),
    });

    if (!response.ok) {
        throw new Error('Error al marcar como "Me gusta"');
    }
    return await response.json();
}

export async function watchLaterMovie(movieId) {
    const response = await fetch(`${API_URL}/watchLaterMovie`, {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ movieId }),
    });

    if (!response.ok) {
        throw new Error('Error al agregar a "Ver más tarde"');
    }
    return await response.json();
}