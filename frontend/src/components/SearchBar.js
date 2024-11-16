// src/components/SearchBar.js
import React from 'react';
import '../styles/SearchBar.css';


const SearchBar = ({ query, setQuery, onSearch }) => {
    const handleInputChange = (e) => {
        setQuery(e.target.value);
    };

    const handleKeyPress = (e) => {
        if (e.key === 'Enter') {
            onSearch();
        }
    };

    return (
        <div className="search-bar">
            <input
                type="text"
                value={query}
                onChange={handleInputChange}
                onKeyPress={handleKeyPress}
                placeholder="Buscar películas..."
            />
            <button onClick={onSearch}>Buscar</button>
        </div>
    );
};

export default SearchBar;
