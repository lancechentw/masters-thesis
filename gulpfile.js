var gulp = require('gulp');
var gutil = require('gulp-util');
var spawn = require('child_process').spawn;

var paths = {
    svgfiles: 'img/src/*.svg',
    srcfiles: ['*.tex', 'img/*', 'source/*']
};

gulp.task('svg', function () {
    var child = spawn('make', ['-B'], { cwd: 'img' });
    child.on('exit', function (code) {
        gutil.log('Exit with code', code);
    });
});

gulp.task('src', function () {
    var child = spawn('make', ['-B'], { cwd: process.cwd() });
    child.on('exit', function (code) {
        gutil.log('Exit with code', code);
    });
});

gulp.task('watch', function () {
    gulp.watch(paths.svgfiles, ['svg']);
    gulp.watch(paths.srcfiles, ['src']);
});

gulp.task('build', ['svg', 'src']);
gulp.task('default', ['build']);
