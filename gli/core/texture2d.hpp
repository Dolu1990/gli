///////////////////////////////////////////////////////////////////////////////////////////////////
// OpenGL Image Copyright (c) 2008 - 2011 G-Truc Creation (www.g-truc.net)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Created : 2010-01-09
// Updated : 2010-01-09
// Licence : This source is under MIT License
// File    : gli/core/texture2d.hpp
///////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef GLI_CORE_TEXTURE2D_INCLUDED
#define GLI_CORE_TEXTURE2D_INCLUDED

#include "image2d.hpp"

namespace gli
{
	//template <template <typename> class mem>
	class texture2D
	{
	public:
		typedef glm::uvec2 dimensions_type;
		typedef glm::vec2 texcoord_type;
		typedef glm::uint32 size_type;
		typedef glm::byte value_type;
		typedef gli::format format_type;
		typedef std::size_t level_type;
		typedef shared_array<value_type> data_type;

	public:
		texture2D();

		explicit texture2D(level_type const & Levels);
		//texture2D(image const & Mipmap, bool GenerateMipmaps = false);

		~texture2D();

		image2D & operator[] (
			level_type const & Level);
		image2D const & operator[] (
			level_type const & Level) const;

		bool empty() const;
		level_type levels() const;
		format_type format() const;

		template <typename genType>
		void swizzle(glm::comp X, glm::comp Y, glm::comp Z, glm::comp W);

	private:
		std::vector<image2D> Images;
	};

//namespace wip
//{
//	// plain
//	template <typename genType>
//	class plain
//	{
//	public:
//		
//	private:
//		boost::shared_array<genType> Data;
//	};
//
//	// texture2D
//	template
//	<
//		typename genType, 
//		template <typename> class surface = plain
//	>
//	class texture2D
//	{
//	public:
//		typedef genType value_type;
//
//	private:
//		class image_impl
//		{
//		public:
//			template <typename coordType>
//			value_type const & operator() (coordType const & Coord) const;
//
//		private:
//			surface<value_type> Surface;
//		};
//
//	public:
//		typedef image_impl image;
//		typedef std::vector<image> mipmaps;
//		typedef typename mipmaps::size_type level_type;
//
//		level_type levels() const;
//		image & operator[] (level_type Level);
//		image const & operator[] (level_type Level) const;
//
//	private:
//		mipmaps Mipmaps;
//	};
//
//}//namespace wip
}//namespace gli

#include "texture2d.inl"

#endif//GLI_CORE_TEXTURE2D_INCLUDED
