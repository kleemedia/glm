///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2012 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file glm/core/type_mat4x2.inl
/// @date 2006-10-01 / 2011-06-15
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

namespace glm{
namespace detail
{
    template <typename T>
    GLM_FUNC_QUALIFIER GLM_CONSTEXPR typename tmat4x2<T>::size_type tmat4x2<T>::length() const
    {
        return 4;
    }

	template <typename T>
	GLM_FUNC_QUALIFIER typename tmat4x2<T>::size_type tmat4x2<T>::col_size()
	{
		return 2;
	}

	template <typename T>
	GLM_FUNC_QUALIFIER typename tmat4x2<T>::size_type tmat4x2<T>::row_size()
	{
		return 4;
	}

	//////////////////////////////////////
	// Accesses

	template <typename T>
	GLM_FUNC_QUALIFIER typename tmat4x2<T>::col_type & 
	tmat4x2<T>::operator[]
	(
		size_type i
	)
	{
		assert(i < this->length());
		return this->value[i];
	}

	template <typename T>
	GLM_FUNC_QUALIFIER typename tmat4x2<T>::col_type const & 
	tmat4x2<T>::operator[]
	(
		size_type i
	) const
	{
		assert(i < this->length());
		return this->value[i];
	}

    //////////////////////////////////////////////////////////////
    // Constructors

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2()
    {
		value_type const Zero(0);
		value_type const One(1);
        this->value[0] = col_type(One, Zero);
        this->value[1] = col_type(Zero, One);
        this->value[2] = col_type(Zero, Zero);
        this->value[3] = col_type(Zero, Zero);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		tmat4x2<T> const & m
	)
    {
        this->value[0] = m.value[0];
        this->value[1] = m.value[1];
        this->value[2] = m.value[2];
        this->value[3] = m.value[3];
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		ctor
	)
    {}

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		value_type const & s
	)
    {
		value_type const Zero(0);
        this->value[0] = col_type(s, Zero);
        this->value[1] = col_type(Zero, s);
        this->value[2] = col_type(Zero, Zero);
        this->value[3] = col_type(Zero, Zero);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
    (
        value_type const & x0, value_type const & y0,
        value_type const & x1, value_type const & y1,
        value_type const & x2, value_type const & y2,
        value_type const & x3, value_type const & y3
    )
    {
        this->value[0] = col_type(x0, y0);
        this->value[1] = col_type(x1, y1);
        this->value[2] = col_type(x2, y2);
        this->value[3] = col_type(x3, y3);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
    (
        col_type const & v0, 
        col_type const & v1, 
        col_type const & v2,
        col_type const & v3
    )
    {
        this->value[0] = v0;
        this->value[1] = v1;
        this->value[2] = v2;
        this->value[3] = v3;
    }

	//////////////////////////////////////
	// Convertion constructors
	template <typename T> 
	template <typename U> 
	GLM_FUNC_DECL tmat4x2<T>::tmat4x2
	(
		U const & s
	)
	{
		value_type const Zero(0);
        this->value[0] = tvec2<T>(value_type(s), Zero);
        this->value[1] = tvec2<T>(Zero, value_type(s));
        this->value[2] = tvec2<T>(Zero, Zero);
        this->value[3] = tvec2<T>(Zero, Zero);
	}
	
	template <typename T> 
	template <
		typename X1, typename Y1, 
		typename X2, typename Y2, 
		typename X3, typename Y3, 
		typename X4, typename Y4>  
	GLM_FUNC_DECL tmat4x2<T>::tmat4x2
	(
		X1 const & x1, Y1 const & y1, 
		X2 const & x2, Y2 const & y2,
		X3 const & x3, Y3 const & y3,
		X4 const & x4, Y4 const & y4
	)		
	{
        this->value[0] = col_type(value_type(x1), value_type(y1));
        this->value[1] = col_type(value_type(x2), value_type(y2));
        this->value[2] = col_type(value_type(x3), value_type(y3));
		this->value[3] = col_type(value_type(x4), value_type(y4));
	}
	
	template <typename T> 
	template <typename V1, typename V2, typename V3, typename V4> 
	GLM_FUNC_DECL tmat4x2<T>::tmat4x2
	(
		tvec2<V1> const & v1, 
		tvec2<V2> const & v2, 
		tvec2<V3> const & v3,
		tvec2<V4> const & v4
	)		
	{
        this->value[0] = col_type(v1);
        this->value[1] = col_type(v2);
        this->value[2] = col_type(v3);
		this->value[3] = col_type(v4);
	}

    // Conversion
    template <typename T> 
    template <typename U> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		tmat4x2<U> const & m
	)
    {
        this->value[0] = col_type(m[0]);
        this->value[1] = col_type(m[1]);
        this->value[2] = col_type(m[2]);
        this->value[3] = col_type(m[3]);
	}

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		tmat2x2<T> const & m
	)
    {
        this->value[0] = col_type(m[0]);
        this->value[1] = col_type(m[1]);
        this->value[2] = col_type(value_type(0));
        this->value[3] = col_type(value_type(0));
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		tmat3x3<T> const & m
	)
    {
        this->value[0] = col_type(m[0]);
        this->value[1] = col_type(m[1]);
        this->value[2] = col_type(m[2]);
        this->value[3] = col_type(value_type(0));
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		tmat4x4<T> const & m
	)
    {
        this->value[0] = col_type(m[0]);
        this->value[1] = col_type(m[1]);
        this->value[2] = col_type(m[2]);
        this->value[3] = col_type(m[3]);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		tmat2x3<T> const & m
	)
    {
        this->value[0] = col_type(m[0]);
        this->value[1] = col_type(m[1]);
        this->value[2] = col_type(value_type(0));
        this->value[3] = col_type(value_type(0));
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		tmat3x2<T> const & m
	)
    {
        this->value[0] = col_type(m[0]);
        this->value[1] = col_type(m[1]);
        this->value[2] = col_type(m[2]);
        this->value[3] = col_type(value_type(0));
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		tmat2x4<T> const & m
	)
    {
        this->value[0] = col_type(m[0]);
        this->value[1] = col_type(m[1]);
        this->value[2] = col_type(value_type(0));
        this->value[3] = col_type(value_type(0));
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		tmat4x3<T> const & m
	)
    {
        this->value[0] = col_type(m[0]);
        this->value[1] = col_type(m[1]);
        this->value[2] = col_type(m[2]);
        this->value[3] = col_type(m[3]);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>::tmat4x2
	(
		tmat3x4<T> const & m
	)
    {
        this->value[0] = col_type(m[0]);
        this->value[1] = col_type(m[1]);
        this->value[2] = col_type(m[2]);
        this->value[3] = col_type(value_type(0));
    }

    //////////////////////////////////////////////////////////////
    // Unary updatable operators

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T>& tmat4x2<T>::operator= 
	(
		tmat4x2<T> const & m
	)
    {
        this->value[0] = m[0];
        this->value[1] = m[1];
        this->value[2] = m[2];
        this->value[3] = m[3];
        return *this;
    }

    template <typename T> 
	template <typename U> 
    GLM_FUNC_QUALIFIER tmat4x2<T>& tmat4x2<T>::operator= 
	(
		tmat4x2<U> const & m
	)
    {
        this->value[0] = m[0];
        this->value[1] = m[1];
        this->value[2] = m[2];
        this->value[3] = m[3];
        return *this;
    }

    template <typename T> 
	template <typename U> 
    GLM_FUNC_QUALIFIER tmat4x2<T> & tmat4x2<T>::operator+= 
	(
		U const & s
	)
    {
        this->value[0] += s;
        this->value[1] += s;
        this->value[2] += s;
        this->value[3] += s;
        return *this;
    }

    template <typename T> 
	template <typename U> 
    GLM_FUNC_QUALIFIER tmat4x2<T> & tmat4x2<T>::operator+= 
	(
		tmat4x2<U> const & m
	)
    {
        this->value[0] += m[0];
        this->value[1] += m[1];
        this->value[2] += m[2];
        this->value[3] += m[3];
        return *this;
    }

    template <typename T> 
	template <typename U> 
    GLM_FUNC_QUALIFIER tmat4x2<T> & tmat4x2<T>::operator-= 
	(
		U const & s
	)
    {
        this->value[0] -= s;
        this->value[1] -= s;
        this->value[2] -= s;
        this->value[3] -= s;
        return *this;
    }

    template <typename T> 
	template <typename U> 
    GLM_FUNC_QUALIFIER tmat4x2<T> & tmat4x2<T>::operator-= 
	(
		tmat4x2<U> const & m
	)
    {
        this->value[0] -= m[0];
        this->value[1] -= m[1];
        this->value[2] -= m[2];
        this->value[3] -= m[3];
        return *this;
    }

    template <typename T> 
	template <typename U> 
    GLM_FUNC_QUALIFIER tmat4x2<T> & tmat4x2<T>::operator*= 
	(
		U const & s
	)
    {
        this->value[0] *= s;
        this->value[1] *= s;
        this->value[2] *= s;
        this->value[3] *= s;
        return *this;
    }

    template <typename T> 
	template <typename U> 
    GLM_FUNC_QUALIFIER tmat4x2<T> & tmat4x2<T>::operator*= 
	(
		tmat4x2<U> const & m
	)
    {
        return (*this = tmat4x2<T>(*this * m));
    }

    template <typename T>
	template <typename U> 
    GLM_FUNC_QUALIFIER tmat4x2<T> & tmat4x2<T>::operator/= 
	(
		U const & s
	)
    {
        this->value[0] /= s;
        this->value[1] /= s;
        this->value[2] /= s;
        this->value[3] /= s;
        return *this;
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> & tmat4x2<T>::operator++ ()
    {
        ++this->value[0];
        ++this->value[1];
        ++this->value[2];
        ++this->value[3];
        return *this;
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> & tmat4x2<T>::operator-- ()
    {
        --this->value[0];
        --this->value[1];
        --this->value[2];
        --this->value[3];
        return *this;
    }

    //////////////////////////////////////////////////////////////
    // Binary operators

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> operator+ 
	(
		tmat4x2<T> const & m, 
		typename tmat4x2<T>::value_type const & s
	)
    {
        return tmat4x2<T>(
            m[0] + s,
            m[1] + s,
            m[2] + s,
            m[3] + s);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> operator+ 
	(	
		tmat4x2<T> const & m1, 
		tmat4x2<T> const & m2
	)
    {
        return tmat4x2<T>(
            m1[0] + m2[0],
            m1[1] + m2[1],
            m1[2] + m2[2],
            m1[3] + m2[3]);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> operator- 
	(
		tmat4x2<T> const & m, 
		typename tmat4x2<T>::value_type const & s
	)
    {
        return tmat4x2<T>(
            m[0] - s,
            m[1] - s,
            m[2] - s,
            m[3] - s);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> operator- 
	(	
		tmat4x2<T> const & m1, 
		tmat4x2<T> const & m2
	)
    {
        return tmat4x2<T>(
            m1[0] - m2[0],
            m1[1] - m2[1],
            m1[2] - m2[2],
            m1[3] - m2[3]);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> operator* 
	(
		tmat4x2<T> const & m, 
		typename tmat4x2<T>::value_type const & s
	)
    {
        return tmat4x2<T>(
            m[0] * s,
            m[1] * s,
            m[2] * s,
            m[3] * s);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> operator* 
	(
		typename tmat4x2<T>::value_type const & s, 
		tmat4x2<T> const & m
	)
    {
        return tmat4x2<T>(
            m[0] * s,
            m[1] * s,
            m[2] * s,
            m[3] * s);
    }

    template <typename T>
    GLM_FUNC_QUALIFIER typename tmat4x2<T>::col_type operator* 
	(
		tmat4x2<T> const & m, 
		typename tmat4x2<T>::row_type const & v)
    {
        return typename tmat4x2<T>::col_type(
            m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0] * v.w,
            m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1] * v.w);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER typename tmat4x2<T>::row_type operator* 
	(
		typename tmat4x2<T>::col_type const & v, 
		tmat4x2<T> const & m) 
    {
        return typename tmat4x2<T>::row_type(
            v.x * m[0][0] + v.y * m[0][1],
            v.x * m[1][0] + v.y * m[1][1],
            v.x * m[2][0] + v.y * m[2][1],
            v.x * m[3][0] + v.y * m[3][1]);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat2x2<T> operator* 
	(
		tmat4x2<T> const & m1, 
		tmat2x4<T> const & m2
	)
    {
        T const SrcA00 = m1[0][0];
        T const SrcA01 = m1[0][1];
        T const SrcA10 = m1[1][0];
        T const SrcA11 = m1[1][1];
        T const SrcA20 = m1[2][0];
        T const SrcA21 = m1[2][1];
        T const SrcA30 = m1[3][0];
        T const SrcA31 = m1[3][1];

        T const SrcB00 = m2[0][0];
        T const SrcB01 = m2[0][1];
        T const SrcB02 = m2[0][2];
        T const SrcB03 = m2[0][3];
        T const SrcB10 = m2[1][0];
        T const SrcB11 = m2[1][1];
        T const SrcB12 = m2[1][2];
        T const SrcB13 = m2[1][3];

        tmat2x2<T> Result(tmat2x2<T>::null);
        Result[0][0] = SrcA00 * SrcB00 + SrcA10 * SrcB01 + SrcA20 * SrcB02 + SrcA30 * SrcB03;
        Result[0][1] = SrcA01 * SrcB00 + SrcA11 * SrcB01 + SrcA21 * SrcB02 + SrcA31 * SrcB03;
        Result[1][0] = SrcA00 * SrcB10 + SrcA10 * SrcB11 + SrcA20 * SrcB12 + SrcA30 * SrcB13;
        Result[1][1] = SrcA01 * SrcB10 + SrcA11 * SrcB11 + SrcA21 * SrcB12 + SrcA31 * SrcB13;
        return Result;
    }

	template <typename T>
	GLM_FUNC_QUALIFIER tmat3x2<T> operator* 
	(
		tmat4x2<T> const & m1, 
		tmat3x4<T> const & m2
	)
	{
		return tmat3x2<T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3]);
	}

	template <typename T>
	GLM_FUNC_QUALIFIER tmat4x2<T> operator* 
	(
		tmat4x2<T> const & m1, 
		tmat4x4<T> const & m2
	)
	{
		return tmat4x2<T>(
			m1[0][0] * m2[0][0] + m1[1][0] * m2[0][1] + m1[2][0] * m2[0][2] + m1[3][0] * m2[0][3],
			m1[0][1] * m2[0][0] + m1[1][1] * m2[0][1] + m1[2][1] * m2[0][2] + m1[3][1] * m2[0][3],
			m1[0][0] * m2[1][0] + m1[1][0] * m2[1][1] + m1[2][0] * m2[1][2] + m1[3][0] * m2[1][3],
			m1[0][1] * m2[1][0] + m1[1][1] * m2[1][1] + m1[2][1] * m2[1][2] + m1[3][1] * m2[1][3],
			m1[0][0] * m2[2][0] + m1[1][0] * m2[2][1] + m1[2][0] * m2[2][2] + m1[3][0] * m2[2][3],
			m1[0][1] * m2[2][0] + m1[1][1] * m2[2][1] + m1[2][1] * m2[2][2] + m1[3][1] * m2[2][3],
			m1[0][0] * m2[3][0] + m1[1][0] * m2[3][1] + m1[2][0] * m2[3][2] + m1[3][0] * m2[3][3],
			m1[0][1] * m2[3][0] + m1[1][1] * m2[3][1] + m1[2][1] * m2[3][2] + m1[3][1] * m2[3][3]);
	}

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> operator/ 
	(
		tmat4x2<T> const & m, 
		typename tmat4x2<T>::value_type const & s
	)
    {
        return tmat4x2<T>(
            m[0] / s,
            m[1] / s,
            m[2] / s,
            m[3] / s);        
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> operator/ 
	(
		typename tmat4x2<T>::value_type const & s, 
		tmat4x2<T> const & m
	)
    {
        return tmat4x2<T>(
            s / m[0],
            s / m[1],
            s / m[2],
            s / m[3]);        
    }

	// Unary constant operators
    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> const operator- 
	(
		tmat4x2<T> const & m
	)
    {
        return tmat4x2<T>(
            -m[0], 
            -m[1], 
            -m[2], 
            -m[3]);
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> const operator++ 
	(
		tmat4x2<T> const & m, 
		int
	) 
    {
        return tmat4x2<T>(
			m[0] + typename tmat4x2<T>::value_type(1),
            m[1] + typename tmat4x2<T>::value_type(1),
            m[2] + typename tmat4x2<T>::value_type(1),
            m[3] + typename tmat4x2<T>::value_type(1));
    }

    template <typename T> 
    GLM_FUNC_QUALIFIER tmat4x2<T> const operator-- 
	(
		tmat4x2<T> const & m, 
		int
	) 
    {
        return tmat4x2<T>(
            m[0] - typename tmat4x2<T>::value_type(1),
            m[1] - typename tmat4x2<T>::value_type(1),
            m[2] - typename tmat4x2<T>::value_type(1),
            m[3] - typename tmat4x2<T>::value_type(1));
    }

	//////////////////////////////////////
	// Boolean operators

	template <typename T> 
	GLM_FUNC_QUALIFIER bool operator==
	(
		tmat4x2<T> const & m1, 
		tmat4x2<T> const & m2
	)
	{
		return (m1[0] == m2[0]) && (m1[1] == m2[1]) && (m1[2] == m2[2]) && (m1[3] == m2[3]);
	}

	template <typename T> 
	GLM_FUNC_QUALIFIER bool operator!=
	(
		tmat4x2<T> const & m1, 
		tmat4x2<T> const & m2
	)
	{
		return (m1[0] != m2[0]) || (m1[1] != m2[1]) || (m1[2] != m2[2]) || (m1[3] != m2[3]);
	}

} //namespace detail
} //namespace glm
