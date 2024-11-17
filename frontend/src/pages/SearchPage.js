// src/pages/SearchPage.js

import React, { useState } from 'react';
import SearchBar from '../components/SearchBar';
import MovieList from '../components/MovieList';
import Sidebar from '../components/Sidebar';
import { searchMovies } from '../api/movies';
import '../styles/SearchPage.css';

const SearchPage = ({ onLogout }) => {
    const [query, setQuery] = useState('');
    const [movies, setMovies] = useState([]);
    const [error, setError] = useState(null);

    const handleSearch = async () => {
        try {
            console.log('Buscando películas con:', { query, username: localStorage.getItem('username') });
            const results = await searchMovies(query); // Llamada a la API para buscar películas
            setMovies(results); // Guarda los resultados de la búsqueda en el estado de películas
            setError(null); // Limpia cualquier error previo
        } catch (err) {
            setError("No se pudo realizar la búsqueda. Intenta nuevamente.");
            setMovies([]); // Si hay un error, limpia los resultados de búsqueda
        }
    };
    
    

    return (
        <div className="search-page">
            <button onClick={onLogout} className="logout-button">Cerrar sesión</button>
            <div className="content-container">
                <div className="search-container">
                    <h2>Buscar Películas</h2>
                    <SearchBar query={query} setQuery={setQuery} onSearch={handleSearch} />
                    {error && <p className="error-message">{error}</p>}
                    <MovieList movies={movies} />
                    {movies.length === 0 && !error && <p>No se encontraron películas.</p>}
                </div>
                <Sidebar />
            </div>
        </div>
    );
};

export default SearchPage;
