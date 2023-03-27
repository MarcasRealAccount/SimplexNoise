#pragma once

#include <cstddef>
#include <cstdint>

namespace SimplexNoise
{
	struct Grad2D
	{
		double dx, dy;
	};

	struct Grad3D
	{
		double dx, dy, dz;
	};

	struct Grad4D
	{
		double dx, dy, dz, dw;
	};

	struct LatticePoint2D
	{
		std::int64_t xsv, ysv;
		double       dx, dy;
	};

	struct LatticePoint3D
	{
		std::int64_t    xrv, yrv, zrv;
		double          dxr, dyr, dzr;
		LatticePoint3D* nextOnFailure;
		LatticePoint3D* nextOnSuccess;
	};

	struct LatticeTree3D
	{
		LatticePoint3D c1, c2, c3, c4, c5, c6, c7, c8, c9, cA, cB, cC, cD;
	};

	struct LatticePoint4DF
	{
		std::int64_t xsv, ysv, zsv, wsv;
		double       dx, dy, dz, dw;
		double       xsi, ysi, zsi, wsi;
		double       ssiDelta;
	};

	struct LatticePoint4DS
	{
		std::int64_t xsv, ysv, zsv, wsv;
		double       dx, dy, dz, dw;
	};

	struct LatticeVec4DS
	{
		std::uint8_t     length;
		LatticePoint4DS* data[20];
	};

	class Noise2D
	{
	public:
		Noise2D(std::uint64_t seed = 0ULL, bool smooth = true);
		Noise2D(Noise2D&& move) noexcept;
		~Noise2D();

		void          SetSeed(std::uint64_t seed);
		std::uint64_t GetSeed() const;

		void SetSmooth(bool smooth);
		bool IsSmooth() const;

		double Sample(double x, double y);
		double SampleXBeforeY(double x, double y);

	private:
		void Setup();

		double SampleBase(double xs, double ys);

	private:
		struct State
		{
			std::uint16_t Perm[2048];
			Grad2D        PermGrads[2048];
		};

		std::uint64_t   m_Seed;
		bool            m_Smooth;
		bool            m_Changed;
		LatticePoint2D* m_LatticePoints;
		std::size_t     m_Iters;
		double          m_R;
		State*          m_State;
	};

	class Noise3D
	{
	public:
		Noise3D(std::uint64_t seed = 0ULL, bool smooth = true);
		Noise3D(Noise3D&& move) noexcept;
		~Noise3D();

		void          SetSeed(std::uint64_t seed);
		std::uint64_t GetSeed() const;

		void SetSmooth(bool smooth);
		bool IsSmooth() const;

		double Sample(double x, double y, double z);
		double SampleXYBeforeZ(double x, double y, double z);
		double SampleXZBeforeY(double x, double y, double z);

	private:
		void Setup();

		double SampleBCC(double xr, double yr, double zr);

	private:
		struct State
		{
			std::uint16_t Perm[2048];
			Grad3D        PermGrads[2048];
		};

		std::uint64_t   m_Seed;
		bool            m_Smooth;
		bool            m_Changed;
		LatticePoint3D* m_LatticePoints;
		double          m_R;
		State*          m_State;
	};

	class Noise4D
	{
	public:
		Noise4D(std::uint64_t seed = 0ULL, bool smooth = true);
		Noise4D(Noise4D&& move) noexcept;
		~Noise4D();

		void          SetSeed(std::uint64_t seed);
		std::uint64_t GetSeed() const;

		void SetSmooth(bool smooth);
		bool IsSmooth() const;

		double Sample(double x, double y, double z, double w);
		double SampleXYBeforeZW(double x, double y, double z, double w);
		double SampleXZBeforeYW(double x, double y, double z, double w);
		double SampleXYZBeforeW(double x, double y, double z, double w);

	private:
		void Setup();

		double SampleBase(double xs, double ys, double zs, double ws);

	private:
		struct State
		{
			std::uint16_t Perm[2048];
			Grad4D        PermGrads[2048];
		};

		std::uint64_t    m_Seed;
		bool             m_Smooth;
		bool             m_Changed;
		LatticePoint4DF* m_LatticePointsF;
		LatticeVec4DS*   m_LatticePointsS;
		double           m_F;
		double           m_F1;
		double           m_F2;
		double           m_F3;
		double           m_F4;
		double           m_F5;
		State*           m_State;
	};
} // namespace SimplexNoise