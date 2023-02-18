# Maintainer: Devin J. Pohly <djpohly+arch@gmail.com>
pkgname=somebar-xorell-git
pkgver=1.0.3.r2.624e929
pkgrel=1
pkgdesc="somebar - dwm-like bar for dwl"
arch=('x86_64')
url="https://git.sr.ht/~raphi/somebar"
license=('GPL')
depends=('meson')
makedepends=('meson' 'git' 'wayland-protocols')
optdepends=('xorg-xwayland: for XWayland support')
provides=("${pkgname%xorell-git}")
conflicts=("${pkgname%xorell-git}")
# append #branch=wlroots-next to build against wlvroots-git
source=('git+https://git.sr.ht/~raphi/somebar')

sha256sums=('SKIP')

prepare() {
	cd "$srcdir/${pkgname%-xorell-git}"

	patch -p1 -t --input "contrib/hide-vacant-tags.patch"
	patch -p1 -t --input "contrib/markup-in-status-messages.patch"

	# This package provides a mechanism to provide a custom config.h. Multiple
	# configuration states are determined by the presence of two files in
	# $BUILDDIR:
	#
	# config.h  config.def.h  state
	# ========  ============  =====
	# absent    absent        Initial state. The user receives a message on how
	#                         to configure this package.
	# absent    present       The user was previously made aware of the
	#                         configuration options and has not made any
	#                         configuration changes. The package is built using
	#                         default values.
	# present                 The user has supplied his or her configuration. The
	#                         file will be copied to $srcdir and used during
	#                         build.
	#
	# After this test, config.def.h is copied from $srcdir to $BUILDDIR to
	# provide an up to date template for the user.
	if [ -e "$BUILDDIR/config.hpp" ]; then
		cp "$BUILDDIR/config.hpp" src/
	elif [ ! -e "$BUILDDIR/config.def.h" ]; then
		msg='This package can be configured in config.h. Copy the config.def.h '
		msg+='that was just placed into the package directory to config.h and '
		msg+='modify it to change the configuration. Or just leave it alone to '
		msg+='continue to use default values.'
		echo "$msg"
	fi
	cp src/config.def.hpp "$BUILDDIR"
}

pkgver() {
	cd "$srcdir/${pkgname%-xorell-git}"
	printf "%s" "$(git describe --long | sed 's/^v//;s/\([^-]*-\)g/r\1/;s/-/./g')"
}

build() {
	cd "$srcdir/${pkgname%-xorell-git}"
	meson setup --prefix "${pkgdir}/usr" build
	arch-meson build
	meson compile -C build
}

package() {
	cd "$srcdir/${pkgname%-xorell-git}"
	meson install -C build
}
